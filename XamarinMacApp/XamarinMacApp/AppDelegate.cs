using AppKit;
using Foundation;


using System.Runtime.InteropServices;

namespace XamarinMacApp
{
    
    [Register("AppDelegate")]
    public class AppDelegate : NSApplicationDelegate
     {
        
        public AppDelegate()
        {
        }

		[DllImport("__Internal")]
		static extern int my_C_Function();
        public override void DidFinishLaunching(NSNotification notification)
        {
            // Insert code here to initialize your application

            int myretval = my_C_Function();

        }

        public override void WillTerminate(NSNotification notification)
        {
            // Insert code here to tear down your application
        }
    }
}
