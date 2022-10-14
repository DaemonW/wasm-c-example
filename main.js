const loadAesLib = require('./aes_cfb.js')


const data = new Uint8Array([1, 2, 3, 4, 5, 6, 7, 8,9 , 10]);
const temp = new Uint8Array(data.length);
const key = new Uint8Array([1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2]);
const iv = new Uint8Array([1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6]);


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

