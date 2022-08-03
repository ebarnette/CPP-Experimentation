#include "pch.h"
#include "MainPage.h"
#include "MainPage.g.cpp"


using namespace winrt;
using namespace winrt::Windows::Media::Capture;
using namespace Windows::UI::Xaml;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::Graphics::Display;

namespace winrt::CameraEffectSelector::implementation
{
    MediaCapture mediaCapture;

    MainPage::MainPage()
    {
        InitializeComponent();
        InitializeCameraAsync();
    }

    int32_t MainPage::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void MainPage::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    IAsyncAction MainPage::InitializeCameraAsync()
    {
        try
        {
            mediaCapture = MediaCapture();
            co_await mediaCapture.InitializeAsync();
        }
        catch (winrt::hresult_error const& ex)
        {
            // No camera
        }

        try
        {
            CameraPreview().Source() = mediaCapture;
            co_await mediaCapture.StartPreviewAsync();
        }
        catch (winrt::hresult_error const& ex)
        {
        }
    }
}
