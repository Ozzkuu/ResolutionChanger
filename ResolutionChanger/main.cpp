#include <Windows.h>
#include <exception>
#include <iostream>

//Quick snippet to swap between two horizontal display resolutions
int main()
{
	int i = 0;
	int y = 0;
	DISPLAY_DEVICE displayDevice;
	DISPLAY_DEVICE primaryDisplay;
	memset(&displayDevice, 0, sizeof(DISPLAY_DEVICE));
	memset(&primaryDisplay, 0, sizeof(DISPLAY_DEVICE));
	displayDevice.cb = sizeof(displayDevice);
	primaryDisplay.cb = sizeof(displayDevice);

	DEVMODE resolutionWidth;
	memset(&resolutionWidth, 0, sizeof(DEVMODE));
	resolutionWidth.dmSize = sizeof(resolutionWidth);
	resolutionWidth.dmDriverExtra = 0;
	//Find the display device with desktop on it

	auto r = EnumDisplayDevices(NULL, i, &displayDevice, DISPLAY_DEVICE_ATTACHED_TO_DESKTOP);
	
		auto result = EnumDisplayDevices(displayDevice.DeviceName, 0, &primaryDisplay, DISPLAY_DEVICE_PRIMARY_DEVICE);

		auto result2 = EnumDisplaySettingsEx(NULL, ENUM_CURRENT_SETTINGS, &resolutionWidth, 0);

		if(resolutionWidth.dmPelsWidth == 3440)
		{
			resolutionWidth.dmPelsWidth = 2560;
			auto result3 = ChangeDisplaySettingsEx(NULL, &resolutionWidth, NULL, 0, NULL);
		}
		else if(resolutionWidth.dmPelsWidth == 2560)
		{
			resolutionWidth.dmPelsWidth = 3440;
			auto result3 = ChangeDisplaySettingsEx(NULL, &resolutionWidth, NULL, 0, NULL);
		}


}