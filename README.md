###FoundationRaise.h

On MacOS X, the header `NSRaise.h` provides several macros for preformatted exceptions that are commonly raised by frameworks:

- Abstract method invocation
- Unimplemented method
- Unimplemented function

These do not exist as part of the iOS SDK. `FoundationRaise.h` provides equivalents for these macros so your iOS projects can be written to raise the expected exceptions.

###Usage

Include the header:
`#import "FoundationRaise.h"`

Using the macros is simple, and they are self-contained. 

A common and powerful design pattern in Objective-C is the [class cluster](https://developer.apple.com/library/ios/documentation/general/conceptual/CocoaEncyclopedia/ClassClusters/ClassClusters.html). A class cluster groups a number of private, concrete subclasses under a public abstract superclass. Primitive methods of the superclass are abstract, and typically throw exceptions when invoked directly.

Using an abstract method as an example, your implemention would be:

	- (BOOL) canFormVoltron {
		NSInvalidAbstractInvocation();
		return NO;
	}
	
This will raise the exception when called:

`caught "NSInvalidArgumentException", "-canFormVoltron only defined for abstract class. Define -[SomeClass canFormVoltron]`

Using `NSUnimplementedMethod()` and `NSUnimplementedFunction()` is similar.
