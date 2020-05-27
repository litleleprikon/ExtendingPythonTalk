.PHONY: build install

CFLAGS = ${shell python3-config --cflags}
LDFLAGS = ${shell python3-config --ldflags}
SITE_PACKAGES = ${shell python3 -c "import site; print(site.getsitepackages()[0])"}

default: build

build: build-go build-c

build-go:
	go build -v -buildmode=c-shared -o GoExtExampleGo.so GoExtExample.go

build-c: GoExtExampleGo.so
	gcc GoExtExample.c -dynamiclib GoExtExampleGo.so -o GoExtExample.so ${CFLAGS} ${LDFLAGS}

install: GoExtExample.so
	cp GoExtExample.so ${SITE_PACKAGES}; \
	cp GoExtExampleGo.so ${SITE_PACKAGES};\

generate-h:
	python3 cgen.py > GoExtExampleAuto.c
