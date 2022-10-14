//iAes.h
extern int EncryptPos;
extern int EncryptStart;
extern int DecryptPos;
extern int DecryptStart;
extern int CounterN;


/**
 * rijndael-alg-fst.h
 *
 * @version 3.0 (December 2000)
 *
 * Optimised ANSI C code for the Rijndael cipher (now AES)
 *
 * @author Vincent Rijmen <vincent.rijmen@esat.kuleuven.ac.be>
 * @author Antoon Bosselaers <antoon.bosselaers@esat.kuleuven.ac.be>
 * @author Paulo Barreto <paulo.barreto@terra.com.br>
 *
 * This code is hereby placed in the public domain.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHORS ''AS IS'' AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

    int AesInit(unsigned char* pKey, int KeySize);
    int SetAESKey(unsigned char* pKey, int KeySize);
    void AesSetIv(unsigned char* pSetIv);
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    #ifndef __RIJNDAEL_ALG_FST_H
    #define __RIJNDAEL_ALG_FST_H
    
    #define MAXKC	(256/32)
    #define MAXKB	(256/8)
    #define MAXNR	14
    
    //typedef unsigned char	u8;
    //typedef unsigned short	u16;
    //typedef unsigned int	u32;
    
    int rijndaelKeySetupEnc();
    int rijndaelKeySetupFitEnc();
    int rijndaelKeySetupDec();
    void rijndaelEncrypt(const unsigned char pt[16], unsigned char ct[16]);
    void rijndaelFitEncrypt(const unsigned char pt[16], unsigned char ct[16]);
    void rijndaelDecrypt(const unsigned char ct[16], unsigned char pt[16]);
    
    #ifdef INTERMEDIATE_VALUE_KAT
    void rijndaelEncryptRound(unsigned char block[16], int rounds);
    void rijndaelDecryptRound(unsigned char block[16], int rounds);
    #endif /* INTERMEDIATE_VALUE_KAT */
    
    #endif /* __RIJNDAEL_ALG_FST_H */
    ///////////////////////////////////////////////////////////////////////////////////////////////////////
    int Encrypt_CFB(unsigned char* pBufferIn, int BufferInSize, unsigned char* pBufferOut);
    int Decrypt_CFB(unsigned char* pBufferIn, int BufferInSize, unsigned char* pBufferOut);
    
    const char* encryptstart(const char *pBufferIn,int BufferInSize,const char *pKey,const char *iV);
    const char* decryptstart(const char *pBufferIn,int BufferInSize,const char *pKey,const char *iV);
    int Compare(const unsigned char* buf1,int size1,const unsigned char* buf2,int size2);
    void Free(const unsigned char* buf);

