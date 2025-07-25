#pragma once

#include "../../Objects/Object.h"

#include "Window/gbe_window.h"
#include "Math/gbe_math.h"
#include "Graphics/gbe_graphics.h"

namespace gbe {
    using namespace gfx;

    /// <summary>
    /// Generic camera class with assignable project matrix and utility functions for rendering.
    /// </summary>
    struct Camera : Object {
        float nearClip;
        float farClip;

        Window* mWindow;

        Camera(Window* mWindow);

        Vector3 WorldUp = Vector3(0, 1, 0);

        Matrix4 GetViewMat();
        virtual Matrix4 getproj() = 0;
        Vector3 ScreenToRay(Vector2 normalizedscreenpos);
        Vector2 WorldToScreen(Vector3 worldpos);
    };

    struct OrthographicCamera : public Camera {
        float orthoRange;

        OrthographicCamera(Window* mWindow);

        // Inherited via GDCamera
        virtual Matrix4 getproj() override;
    };

    struct PerspectiveCamera : public Camera {
        float angles;

        PerspectiveCamera(Window* mWindow);

        // Inherited via GDCamera
        virtual Matrix4 getproj() override;
    };
}