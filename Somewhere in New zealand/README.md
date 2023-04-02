## Challenge Description

Rivest and Joan are explorers based in New Zealand. Rivest has a string of coordinates (A) and cryptic names of two stops on the way B and C. Joan has an encoded name of a landmark D. Help them find out the name of their final destination. 

## Writeup
For this question, we had a mix of 2 ciphers: AES and RSA. Rivest was the creator of RSA and Joan was of AES. 
For AES, cipher text was given in the form of B, and the key was given in ASCII. Upon decoding the cipher text with the key (after converting it to string), we obtain the plain text of AES. The plain text of AES served as the private key of  RSA. The cipher text of RSA was provided as C. Using the private key of RSA, C can be decoded to get the flag.
In case you are obtaining any plain text in the form of base 64, convert it to string. 
New Zeland has a country code of 64. So it was to indicate that strings might be in base 64.

## Flag

```
BITSCTF{M0UN7_C00K_15_4_G00D_PL4C3}
```