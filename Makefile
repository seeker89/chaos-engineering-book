all: killer-whiles who-you-gonna-call jvm app

killer-whiles:
	(cd examples/killer-whiles && make)

who-you-gonna-call:
	(cd examples/who-you-gonna-call && make)
	(cd examples/who-you-gonna-call/src && make gen && make)

jvm:
	(cd examples/jvm && make)

clean:
	rm -rf vm/vm.zip vm/parts.sha256 vm/chaos-engineering-VM*

app:
	(cd examples/app && make install)

.PHONY: killer-whiles who-you-gonna-call clean
