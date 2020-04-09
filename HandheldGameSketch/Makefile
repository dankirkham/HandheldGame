BUILD_DIR=build
ARDUINO_CLI=${BUILD_DIR}/bin/arduino-cli
SKETCH=HandheldGameSketch.ino

${BUILD_DIR}/${SKETCH}.hex: ${ARDUINO_CLI} *.cpp *.h
	./${ARDUINO_CLI} compile --fqbn arduino:avr:uno ${SKETCH} -o ${BUILD_DIR}/${SKETCH}

${ARDUINO_CLI}: ${BUILD_DIR}
	cd ${BUILD_DIR} ; curl -fsSL https://raw.githubusercontent.com/arduino/arduino-cli/master/install.sh | sh
	./${ARDUINO_CLI} config init
	./${ARDUINO_CLI} core install arduino:avr

${BUILD_DIR}:
	mkdir -p ${BUILD_DIR}

.PHONY clean:
clean:
	rm -rf ${BUILD_DIR}
