//
//  ResponsiveLabel.h
//  ResponsiveLabel
//
//  Created by hsusmita on 13/03/15.
//  Copyright (c) 2015 hsusmita.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "PatternDescriptor.h"

typedef NS_ENUM(NSInteger, RLTextVerticalAlignment) {
    RLTextVerticalAlignmentCenter      = 0,    // Visually aligned in the middle
    RLTextVerticalAlignmentTop    = 1,         // Visually aligned at the top
    RLTextVerticalAlignmentBottom    = 2    // Visually aligned at the bottom
};


/**
 Custom NSTextAttributeName which takes value of type PatternTapHandler.
 It specifies the action to be performed when a range of text with that attribute is tapped.
 */
extern NSString *RLTapResponderAttributeName;
extern NSString *RLHighlightedForegroundColorAttributeName;
extern NSString *RLHighlightedBackgroundColorAttributeName;

/**
 Type for responder block to be specfied with RLTapResponderAttributeName
 */
typedef void (^PatternTapResponder)(NSString *tappedString);


IB_DESIGNABLE
/**
 UILabel subclass which responds to touch on specified patterns.
 This allows to replace the default truncation token with custom attributed string which can be made tappable
 */

@interface ResponsiveLabel : UILabel

@property (nonatomic,assign) IBInspectable RLTextVerticalAlignment verticalAlignment;

#if __IPHONE_OS_VERSION_MAX_ALLOWED >= 80000

@property (nonatomic,assign) IBInspectable BOOL customTruncationEnabled;
@property (nonatomic,strong) IBInspectable NSString *truncationToken;

#else

@property (nonatomic,assign) BOOL customTruncationEnabled;
@property (nonatomic,strong) NSString *truncationToken;

#endif

/** Method to set custom truncation token
 @param attributedTruncationToken:NSAttributedString Custom truncation token to be used instead of default ellipse
 @param action:PatternTapResponder Action to be performed on tap on truncation token
 */

- (void)setAttributedTruncationToken:(NSAttributedString *)attributedTruncationToken withAction:(PatternTapResponder)action;

/** Method to set an image as truncation indicator
 @param image: UIImage
 @param size: CGSize : The height of image size should be approximately equal to or less than the font height. Otherwise the image will not be rendered properly
 @param action:PatternTapResponder Action to be performed on tap on the image
 */

- (void)setTruncationIndicatorImage:(UIImage *)image withSize:(CGSize)size andAction:(PatternTapResponder)action;


/** Method to set text
 @param text : NSString
 @param withTruncation : BOOL
 */

- (void)setText:(NSString *)text withTruncation:(BOOL)truncation;

/** Method to set attributed text
 @param attributedText: NSAttributedString
 @param withTruncation: BOOL
 */
- (void)setAttributedText:(NSAttributedString *)attributedText withTruncation:(BOOL)truncation;

/**
 Generates pattern, applies attributes and handles touch(If action specified) according to patternDescriptor.
 @param patternDescriptor:PatternDescriptor
 This object encapsulates the regular expression and attributes to be added to the pattern.
 To patterns tappable, add attribute RLTapResponderAttributeName key with block of type PatternTapResponder
 */

- (void)enablePatternDetection:(PatternDescriptor *)patternDescriptor;

/**
 Removes previously applied attributes from all the occurance of pattern dictated by pattern descriptor
 */
- (void)disablePatternDetection:(PatternDescriptor *)patternDescriptor;


/**
 Applies attributes to all the occurances of given string according to the attributes defines in the dictionary.
 @param string: NSString
 @param dictionary: NSDictionary
 A dictionary containing the attributes to add. To make the string tappable, set attribute RLTapResponderAttributeName key with block of type PatternTapResponder
 */

- (void)enableStringDetection:(NSString *)string withAttributes:(NSDictionary*)dictionary;

/**
 Removes previously applied attributes from all the occurances of given string
 @param string: NSString
 */
- (void)disableStringDetection:(NSString *)string;

/**
 Applies attributes to all the occurances of strings specified in the array according to the attributes defines in the dictionary.
 @param stringsArray: NSArray
 @param dictionary: NSDictionary
 A dictionary containing the attributes to add. To make the strings tappable, set attribute RLTapResponderAttributeName key with block of type PatternTapResponder
 */

- (void)enableDetectionForStrings:(NSArray *)stringsArray withAttributes:(NSDictionary*)dictionary;

/**
 Removes previously applied attributes from all the occurances of strings contained in the array
 @param string: NSArray
 */
- (void)disableDetectionForStrings:(NSArray *)stringsArray;

/**
 Applies attributes to all the occurances of hashtags according to the attributes defines in the dictionary.
 @param dictionary: NSDictionary
 A dictionary containing the attributes to add. To make the strings tappable, set attribute RLTapResponderAttributeName key with block of type PatternTapResponder
 */

- (void)enableHashTagDetectionWithAttributes:(NSDictionary*)dictionary;

/**
 Removes previously applied attributes from all the occurance of hashtags
 */
- (void)disableHashTagDetection;

/**
 Applies attributes to all the occurances of urls according to the attributes defines in the dictionary.
 @param dictionary: NSDictionary
 A dictionary containing the attributes to add. To make URLs tappable, set @attribute RLTapResponderAttributeName key with block of type PatternTapResponder
 */

- (void)enableURLDetectionWithAttributes:(NSDictionary*)dictionary;

/**
 Removes previously applied attributes from all the occurance of URLs
 */
- (void)disableURLDetection;

/**
 Applies attributes to all the occurances of user handles according to the attributes defines in the dictionary.
 @param dictionary:NSDictionary
 A dictionary containing the attributes to add. To make userhandles tappable, set @attribute RLTapResponderAttributeName key with block of type PatternTapResponder
 */

- (void)enableUserHandleDetectionWithAttributes:(NSDictionary*)dictionary;

/**
 Removes previously applied attributes from all the occurance of user handles
 */

- (void)disableUserHandleDetection;

@end
