# Glamour-math library

This is a crossplatform C++ linear algebra library. It's extracted from my (suspended) graphics engine, GLamour.

The library is designed to be used in 3D graphics applications, but could also be applied to physics simulation,
2D software and what not.
  
## 3D vectors

Three-dimensional vectors are obviously the meat of 3D graphics. The `Vector3D` class is a high-performance implementation of
3D vectors with many convenient methods for working in 3D space.

    // TODO examples

## 2D vectors

The `Vector2d` class is thrown in for convenience and working with 2D user interface, etc.

    // TODO examples

## 4x4 matrices

The `Matrix4x4` class is designed to take advantage of linear algebra vectors representing 3D orientations and position, but still
allowing perspective transforms (which require adding the fourth dimension to the matrix).

    // TODO examples

## Quaternions

[Quaternions](http://en.wikipedia.org/wiki/Quaternions) in a nutshell are four-dimensional complex numbers. Not giving
into detail much, they are used to correctly interpolate 3D rotation and avoid [gimbal lock](http://en.wikipedia.org/wiki/Gimbal_lock).

    // TODO examples

## Camera

3D graphics usually involve a set of view transforms. To abstract away the math, I created the `Camera` class and its
descendants, `PerspectiveCamera` and `OrthogonalCamera`.

Cameras compile view & projection matrices from a camera position and orientation.óó

    // TODO examples

***

(c) Leonid Shevtsov, written in 2006-2007, open sourced in 2012
