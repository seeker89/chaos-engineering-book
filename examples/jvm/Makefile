CFLAGS=-O0

all: FizzBuzzEnterpriseEdition/bin/FizzBuzzEnterpriseEdition

src:
	git clone https://github.com/EnterpriseQualityCoding/FizzBuzzEnterpriseEdition.git src

FizzBuzzEnterpriseEdition/bin/FizzBuzzEnterpriseEdition: src
	(cd src && ./gradlew assemble && ./gradlew build)
	unzip src/build/distributions/FizzBuzzEnterpriseEdition.zip

run: FizzBuzzEnterpriseEdition/bin/FizzBuzzEnterpriseEdition
	./FizzBuzzEnterpriseEdition/bin/FizzBuzzEnterpriseEdition

.PHONY: run
