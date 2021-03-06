//
//  DMECrypto.h
//  DigiMeSDK
//
//  Created on 25/01/2018.
//  Copyright © 2018 digi.me Limited. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface DMECrypto : NSObject

/**
 Decrypts encrypted data using private key data from specified configuration.

 @param encryptedData NSData
 @param contractId The contract identifier
 @param keyHex The private hex key with which data can be decrypted
 @return NSData - decrypted data or nil if decryption failed.
 */
+ (nullable NSData *)getDataFromEncryptedBytes:(NSData *)encryptedData contractId:(NSString *)contractId privateKeyHex:(NSString *)keyHex;

/**
 Encrypt data using AES256 algorithm.
 
 @param keyData NSData
 @param ivData NSData
 @param data NSData
 @param error NSError
 @return NSData - encrypted data or nil if encryption failed.
 */

+ (nullable NSData *)encryptAes256UsingKey:(NSData *)keyData initializationVector:(NSData *)ivData data:(NSData *)data error:(NSError * __autoreleasing * _Nullable)error;

/**
 Decrypt data using AES256 algorithm.

 @param keyData NSData
 @param ivData NSData
 @param data NSData
 @param error NSError
 @return NSData - decrypted data or nil if decryption failed.
 */
+ (nullable NSData *)decryptAes256UsingKey:(NSData *)keyData initializationVector:(NSData *)ivData data:(NSData *)data error:(NSError * __autoreleasing *)error;

/**
 Generates random data using length as a parameter.
 
 @param length int
 @return NSData - random bytes for the specified length.
 */
+ (NSData *)getRandomUnsignedCharacters:(int)length;

/**
 Encrypts metadata for Postbox with AES encryption
 
 @param metadata NSData
 @param symmetricalKey NSData
 @param iv NSData
 @return NSString - AES encrypted metadata to push to postbox in Base64 encoding.
 */
+ (NSString *)encryptMetadata:(NSData *)metadata symmetricalKey:(NSData *)symmetricalKey initializationVector:(NSData *)iv;

/**
 Encrypts data for Postbox with AES encryption
 
 @param payload NSData
 @param symmetricalKey NSData
 @param iv NSData
 @return NSString - AES encrypted data to push to postbox in a hexadecimal representation.
 */
+ (NSData *)encryptData:(NSData *)payload symmetricalKey:(NSData *)symmetricalKey initializationVector:(NSData *)iv;

/**
 Encrypts Symmetrical Key for Postbox with RSA public key and return it as Base64 encoded.
 
 @param symmetricalKey NSData
 @param contractId The contract identifier.
 @param publicKey NSString
 */
+ (NSString *)encryptSymmetricalKey:(NSData *)symmetricalKey rsaPublicKey:(NSString *)publicKey contractId:(NSString *)contractId;

/**
 Encrypt data using RSA public key.
 
 @param dataToEncrypt NSData
 @param publicKey NSData
 @return NSData - encrypted data or nil if encryption failed.
 */
+ (NSData *)encryptLargeData:(NSData *)dataToEncrypt publicKey:(SecKeyRef)publicKey;

/**
 Decrypt data using RSA private key.
 
 @param dataToDecrypt NSData
 @param privateKey NSData
 @return NSData - decrypted data or nil if decryption failed.
 */
+ (NSData *)decryptLargeData:(NSData *)dataToDecrypt privateKey:(SecKeyRef)privateKey;

@end

NS_ASSUME_NONNULL_END
