#!/bin/sh

if [ -n "$DESTDIR" ] ; then
    case $DESTDIR in
        /*) # ok
            ;;
        *)
            /bin/echo "DESTDIR argument must be absolute... "
            /bin/echo "otherwise python's distutils will bork things."
            exit 1
    esac
fi

echo_and_run() { echo "+ $@" ; "$@" ; }

echo_and_run cd "/home/sumitomo/Documents/SumiyomoAGV/sumitomo_ws/src/rosserial/rosserial_vex_v5"

# ensure that Python install destination exists
echo_and_run mkdir -p "$DESTDIR/home/sumitomo/Documents/SumiyomoAGV/sumitomo_ws/install/lib/python2.7/dist-packages"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
echo_and_run /usr/bin/env \
    PYTHONPATH="/home/sumitomo/Documents/SumiyomoAGV/sumitomo_ws/install/lib/python2.7/dist-packages:/home/sumitomo/Documents/SumiyomoAGV/sumitomo_ws/build/rosserial_vex_v5/lib/python2.7/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/sumitomo/Documents/SumiyomoAGV/sumitomo_ws/build/rosserial_vex_v5" \
    "/usr/bin/python2" \
    "/home/sumitomo/Documents/SumiyomoAGV/sumitomo_ws/src/rosserial/rosserial_vex_v5/setup.py" \
     \
    build --build-base "/home/sumitomo/Documents/SumiyomoAGV/sumitomo_ws/build/rosserial_vex_v5" \
    install \
    --root="${DESTDIR-/}" \
    --install-layout=deb --prefix="/home/sumitomo/Documents/SumiyomoAGV/sumitomo_ws/install" --install-scripts="/home/sumitomo/Documents/SumiyomoAGV/sumitomo_ws/install/bin"
