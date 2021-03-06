//
//  DMEServiceObjectType.h
//  DigiMeSDK
//
//  Created on 21/11/2019.
//  Copyright © 2019 digi.me Limited. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface DMEServiceObjectType: NSObject

/**
 ObjectType is a JFS object definition, such us social Comment, Media, Post etc.
 
  - seealso:
 For more information, see [digi.me Developer Portal]
 (https://developers.digi.me/reference-objects#objects)
 
 ### Useful links
 * [digi.me Developer Portal]
*/
@property (nonatomic, readonly) NSUInteger identifier;

/**
-init unavailable. Use -initWithServiceObjectType:serviceObjectTypeId:

@return instancetype
*/
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

/**
 Designated object initializer.

@param identifier NSNumber Object identifier that is a representation of the JFS Service Object Type entity, such us social Comment, Media or a Post.
@return instancetype.
*/
- (instancetype)initWithIdentifier:(NSUInteger)identifier NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
