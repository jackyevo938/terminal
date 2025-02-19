/*++
Copyright (c) Microsoft Corporation
Licensed under the MIT license.

Module Name:
- ConsoleWindow.hpp

Abstract:
- OneCore implementation of the IConsoleWindow interface.

Author(s):
- Hernan Gatta (HeGatta) 29-Mar-2017
--*/

#pragma once

#include "../inc/IConsoleWindow.hpp"

#pragma hdrstop

namespace Microsoft::Console::Interactivity::OneCore
{
    class ConsoleWindow : public Microsoft::Console::Types::IConsoleWindow
    {
    public:
        // Inherited via IConsoleWindow
        BOOL EnableBothScrollBars() noexcept override;
        int UpdateScrollBar(bool isVertical, bool isAltBuffer, UINT pageSize, int maxSize, int viewportPosition) noexcept override;

        bool IsInFullscreen() const noexcept override;
        void SetIsFullscreen(const bool fFullscreenEnabled) noexcept override;
        void ChangeViewport(const SMALL_RECT NewWindow) override;

        void CaptureMouse() noexcept override;
        BOOL ReleaseMouse() noexcept override;

        HWND GetWindowHandle() const noexcept override;

        void SetOwner() noexcept override;

        BOOL GetCursorPosition(LPPOINT lpPoint) noexcept override;
        BOOL GetClientRectangle(LPRECT lpRect) noexcept override;
        int MapPoints(LPPOINT lpPoints, UINT cPoints) noexcept override;
        BOOL ConvertScreenToClient(LPPOINT lpPoint) noexcept override;

        BOOL SendNotifyBeep() const noexcept override;

        BOOL PostUpdateScrollBars() const noexcept override;
        BOOL PostUpdateWindowSize() const noexcept override;

        void UpdateWindowSize(const COORD coordSizeInChars) noexcept override;
        void UpdateWindowText() noexcept override;

        void HorizontalScroll(const WORD wScrollCommand, const WORD wAbsoluteChange) noexcept override;
        void VerticalScroll(const WORD wScrollCommand, const WORD wAbsoluteChange) noexcept override;

        [[nodiscard]] HRESULT SignalUia(_In_ EVENTID id) noexcept override;
        [[nodiscard]] HRESULT UiaSetTextAreaFocus() noexcept override;
        RECT GetWindowRect() const noexcept override;
    };
}
