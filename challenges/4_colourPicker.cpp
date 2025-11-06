#include <iostream>
using namespace std;
#include <CoreGraphics/CoreGraphics.h>

int main()
{
    int exit = 1; // program is on by default
    while (true)
    {
        cin >> exit; // get user choice, to prevent CPU overload
        if(exit == 0){ // if program is turned off
            return 0; // end program
        } else {
        // NULL event to get current pos
        CGEventRef event = CGEventCreate(NULL);

        // get mouse pos from said NULL event
        CGPoint cursorLocation = CGEventGetLocation(event);

        // clean up event
        CFRelease(event);

        // create 1x1 pixel rectangle
        CGRect pixelRect = CGRectMake(cursorLocation.x, cursorLocation.y, 1, 1);

        // get the main display
        CGDirectDisplayID mainDisplay = CGMainDisplayID();

        // create the 1x1 image from attained display
        CGImageRef image = CGDisplayCreateImageForRect(mainDisplay, pixelRect);

        // get the Image's Data Provider
        CGDataProviderRef provider = CGImageGetDataProvider(image);

        // get the raw data
        CFDataRef data = CGDataProviderCopyData(provider);

        // access the Data Buffer
        const UInt8 *pixelData = CFDataGetBytePtr(data);

        // read the values
        int r = pixelData[0]; // red
        int g = pixelData[1]; // green
        int b = pixelData[2]; // blue
        int a = pixelData[3]; // transparency

        // display the colour at mouse pos
        cout << "Red: " << r << ", Green: " << g << ", Blue: " << b << ", Transparency: " << a << endl;
        CFRelease(data);       // release the data object
        CGImageRelease(image); // release the image object
        }
    }

    return 0;
}