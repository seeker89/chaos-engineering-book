CFLAGS=-O0

all: FizzBuzzEnterpriseEdition.jar

src:
	git clone https://github.com/EnterpriseQualityCoding/FizzBuzzEnterpriseEdition.git src

FizzBuzzEnterpriseEdition.jar: src
	(cd src && ./gradlew assemble && ./gradlew build)
	cp src/build/libs/FizzBuzzEnterpriseEdition.jar .

.PHONY:
