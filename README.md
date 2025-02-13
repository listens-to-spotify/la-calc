```
sudo docker build -t la-calc .
```
```
sudo docker run -it \
    --name qt-container \
    -e QT_QPA_PLATFORM=xcb \
    -e DISPLAY=$DISPLAY \
    -v /tmp/.X11-unix:/tmp/.X11-unix \
    -e XDG_RUNTIME_DIR=/tmp/runtime-root \
    qt-app
```

