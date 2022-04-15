using NewModernWinver.ViewModels;
using System;
using System.ComponentModel;
using System.Threading.Tasks;
using Windows.ApplicationModel.Activation;
using Windows.Foundation;
using Windows.UI.ViewManagement;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Navigation;

namespace NewModernWinver
{
    /// <summary>
    /// Provides application-specific behavior to supplement the default Application class.
    /// </summary>
    sealed partial class App : Application
    {
        public readonly static DeviceInfoViewModel DeviceViewModel =
            new DeviceInfoViewModel();

        public readonly static ThemeViewModel ThemeViewModel =
            new ThemeViewModel();

        private readonly static BackgroundWorker PerfWorker =
            new BackgroundWorker();

        /// <summary>
        /// Initializes the singleton application object.  This is the first line of authored code
        /// executed, and as such is the logical equivalent of main() or WinMain().
        /// </summary>
        public App()
        {
            this.InitializeComponent();

            // Start worker
            PerfWorker.DoWork += (s, e) => UpdatePerformanceData();
            PerfWorker.RunWorkerAsync();
        }

        protected override async void OnActivated(IActivatedEventArgs args)
        {
            if (args.Kind == ActivationKind.Protocol)
            {
                ProtocolActivatedEventArgs eventArgs = args as ProtocolActivatedEventArgs;

                Frame rootFrame = await InitializeViewAsync();

                // Always navigate for a protocol launch
                rootFrame.Navigate(typeof(MainPage), eventArgs.Uri.AbsoluteUri);
            }
        }

        /// <summary>
        /// Invoked when the application is launched normally by the end user.  Other entry points
        /// will be used such as when the application is launched to open a specific file.
        /// </summary>
        /// <param name="e">Details about the launch request and process.</param>
        protected override async void OnLaunched(LaunchActivatedEventArgs e)
        {
            Frame rootFrame = await InitializeViewAsync();
            if (e.PrelaunchActivated == false)
            {
                if (rootFrame.Content == null)
                {
                    rootFrame.Navigate(typeof(MainPage), e.Arguments);
                }
            }
        }

        private async Task<Frame> InitializeViewAsync()
        {
            // Do not repeat app initialization when the Window already has content,
            // just ensure that the window is active
            if (!(Window.Current.Content is Frame rootFrame))
            {
                // Before initializing, set the preferred launch view size
                var size = new Size(436, 635);
                ApplicationView.GetForCurrentView().SetPreferredMinSize(size);

                ApplicationView.PreferredLaunchViewSize = size;
                ApplicationView.PreferredLaunchWindowingMode = ApplicationViewWindowingMode.PreferredLaunchViewSize;

                // Create a Frame to act as the navigation context and navigate to the first page
                rootFrame = new Frame();
                rootFrame.NavigationFailed += OnNavigationFailed;

                // Place the frame in the current Window
                Window.Current.Content = rootFrame;
            }

            // Ensure the current window is active
            Window.Current.Activate();
            await ThemeViewModel.LoadWallpapersAsync();

            return rootFrame;
        }

        /// <summary>
        /// Invoked when Navigation to a certain page fails
        /// </summary>
        /// <param name="sender">The Frame which failed navigation</param>
        /// <param name="e">Details about the navigation failure</param>
        private void OnNavigationFailed(object sender, NavigationFailedEventArgs e)
        {
            throw new Exception("Failed to load Page " + e.SourcePageType.FullName);
        }

        /// <summary>
        /// Keeps performance data up to date.
        /// </summary>
        private void UpdatePerformanceData()
        {
            while (true)
            {
                DeviceViewModel.Update();
                System.Threading.Thread.Sleep(2000);
            }
        }
    }
}
