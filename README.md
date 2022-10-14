#### 编译C代码到WASM



1. 进入项目，执行
   
   ```bash
   bash ./build.sh
   ```

2. 将生成的aes_cfb.js和aes_cfb.wasm拷贝到调用方

3. 在js中调用
   
   ```js
   const loadAesLib = require('./aes_cfb.js')
   loadAesLib().then((instance) => {
       let strData = "origin data: ";
       for (let i = 0; i < data.length; i++) {
           strData = strData + data[i].toString() + "    ";
       }
       console.log(strData);
   
       let len = data.length;
       let ptr1 = instance.ccall('nativeAesEnc', 'number', ['array', 'number', 'array', 'array'], [data, data.length, key, iv]);
       let strEnc = "";
       for (let i = 0; i < len; i++) {
           temp[i] = instance.HEAPU8[ptr1 + i];
           strEnc = strEnc + temp[i].toString() + "    ";
       }
       console.log("AES CFB in WASM: " + strEnc);
   
       let ptr2 = instance.ccall('nativeAesDec', 'number', ['array', 'number', 'array', 'array'], [temp, temp.length, key, iv]);
       let strDec = "";
       for(let i = 0; i<len;i++){
           strDec = strDec + instance.HEAPU8[ptr2 + i].toString() + "    ";
       }
       console.log("decrypt data: " + strDec);
       instance._free(ptr1)
       instance._free(ptr2)
   });
   ```

4. 注意导出的js为Promise，需要异步调用
