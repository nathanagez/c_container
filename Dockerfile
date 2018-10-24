FROM alpine
COPY ./container /home
WORKDIR /home
RUN apk add build-base
RUN apk add sudo
RUN cd /home
RUN sudo tar -zxf rootfs.tar.gz
