FROM ubuntu:latest

ENV DEBIAN_FRONTEND=noninteractive
ENV TZ=Europe/Moscow
ENV QT_QPA_PLATFORM=xcb

# Установка необходимых пакетов
RUN apt-get update && apt-get install -y \
    qt6-base-dev \
    qt6-tools-dev \
    qt6-tools-dev-tools \
    libqt6gui6 \
    libqt6widgets6 \
    qmake6 \
    build-essential \
    g++ \
    libxcb-xinerama0 \
    libxcb1 \
    libxcb-keysyms1 \
    libxcb-icccm4 \
    libeigen3-dev \
    libboost-all-dev \
    xauth \
    x11-apps \
    && rm -rf /var/lib/apt/lists/*


COPY . /app
WORKDIR /app/app


# Сборка проекта
RUN qmake6 la-calc.pro && make

# Запуск приложения (если требуется)
CMD ["./la-calc"]

