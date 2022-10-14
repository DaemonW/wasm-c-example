#!/bin/bash
emcc aes_cfb.c -o aes_cfb.js -sMODULARIZE -sEXPORTED_FUNCTIONS=['_nativeAesEnc','_nativeAesDec','_malloc','_free'] -sEXPORTED_RUNTIME_METHODS=['ccall','cwrap'] -sEXIT_RUNTIME=0
