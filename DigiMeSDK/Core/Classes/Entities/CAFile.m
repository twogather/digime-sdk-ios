//
//  CAFile.m
//  DigiMeSDK
//
//  Created on 24/01/2018.
//  Copyright © 2018 digi.me Limited. All rights reserved.
//

#import "CAFile.h"

@implementation CAFile

#pragma mark - Deserialization
+ (CAFile *)deserialize:(NSData *)data fileId:(NSString *)fileId error:(NSError * _Nullable __autoreleasing *)error
{
    NSArray *content = [NSJSONSerialization JSONObjectWithData:data options:kNilOptions error:error];
    
    CAFile *file = [[self alloc] initWithFileId:fileId];
    [file populateWithContent:content];
    return file;
}

#pragma mark - Initialization

-(instancetype)initWithFileId:(NSString *)fileId
{
    self = [super init];
    if (self)
    {
        _fileId = fileId;
    }
    
    return self;
}

#pragma mark - Public

- (void)populateWithContent:(NSArray *)content
{
    _json = content;
}

#pragma mark - Overrides

-(NSString *)description
{
    NSString *description = [NSString stringWithFormat:@"FileId: %@,\n", self.fileId];
    
    description = [NSString stringWithFormat:@"%@%i objects", description, (int)self.json.count];
    
    return [NSString stringWithFormat:@"\n<%@: %p,\n%@>",
            NSStringFromClass([self class]), self, description];
}

@end
