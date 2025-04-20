FROM qmkfm/qmk_cli

VOLUME /qmk_firmware
WORKDIR /qmk_firmware

CMD qmk compile -kb jzg/cardboard68 -km default
