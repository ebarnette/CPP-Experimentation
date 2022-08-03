#pragma once

#include "MainPage.g.h"

namespace winrt::CameraEffectSelector::implementation
{
    struct MainPage : MainPageT<MainPage>
    {
        MainPage();

        int32_t MyProperty();
        void MyProperty(int32_t value);

        winrt::Windows::Foundation::IAsyncAction InitializeCameraAsync();
    };
}

namespace winrt::CameraEffectSelector::factory_implementation
{
    struct MainPage : MainPageT<MainPage, implementation::MainPage>
    {
    };
}
