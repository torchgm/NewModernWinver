using System;
using System.Threading.Tasks;
using Windows.Graphics.Imaging;
using Windows.Storage;
using Windows.Storage.Streams;
using Windows.UI.Xaml.Media.Imaging;

namespace NewModernWinver.Misc
{
    public static class ImageHelpers
    {
        public static async Task<WriteableBitmap> GetBitmapAsync
            (this StorageFile file, int width, int height)
        {
            using (var fileStream = await file.OpenReadAsync())
            {
                return await fileStream.GetBitmapAsync(width, height);
            }
        }

        public static async Task<WriteableBitmap> GetBitmapAsync
            (this IRandomAccessStream stream, int width, int height)
        {
            using (var memoryStream = new InMemoryRandomAccessStream())
            {
                var decoder = await BitmapDecoder.CreateAsync(stream);
                var transform = new BitmapTransform
                {
                    ScaledWidth = (uint)width,
                    ScaledHeight = (uint)height,
                    InterpolationMode = BitmapInterpolationMode.Cubic
                };

                var pixelData = await decoder.GetPixelDataAsync(
                    BitmapPixelFormat.Bgra8, BitmapAlphaMode.Straight, transform,
                    ExifOrientationMode.RespectExifOrientation,
                    ColorManagementMode.ColorManageToSRgb);

                var pixels = pixelData.DetachPixelData();

                var encoder = await BitmapEncoder.CreateAsync(
                    BitmapEncoder.PngEncoderId, memoryStream);

                encoder.SetPixelData(
                    BitmapPixelFormat.Bgra8, BitmapAlphaMode.Straight,
                    (uint)width, (uint)height, 96, 96, pixels);

                await encoder.FlushAsync();
                memoryStream.Seek(0);

                var bitmap = new WriteableBitmap(width, height);
                await bitmap.SetSourceAsync(memoryStream);

                return bitmap;
            }
        }

        public static async Task<SoftwareBitmapSource> GetSourceAsync(this SoftwareBitmap bitmap)
        {
            if (bitmap.BitmapPixelFormat != BitmapPixelFormat.Bgra8 ||
                bitmap.BitmapAlphaMode == BitmapAlphaMode.Straight)
            {
                bitmap = SoftwareBitmap.Convert(bitmap, BitmapPixelFormat.Bgra8,
                    BitmapAlphaMode.Premultiplied);
            }

            var source = new SoftwareBitmapSource();
            await source.SetBitmapAsync(bitmap);

            return source;
        }

        public static async Task<SoftwareBitmapSource> GetSourceAsync(this WriteableBitmap bitmap)
        {
            var bmp = SoftwareBitmap.CreateCopyFromBuffer(
                bitmap.PixelBuffer,
                BitmapPixelFormat.Bgra8,
                bitmap.PixelWidth,
                bitmap.PixelHeight
            );

            return await bmp.GetSourceAsync();
        }
    }
}
