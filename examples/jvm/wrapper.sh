#! /bin/bash

echo "Our pid is" $$
echo "Press enter to start FizzBuzzEnterprise"
read

exec java -classpath "./FizzBuzzEnterpriseEdition/lib/*" com.seriouscompany.business.java.fizzbuzz.packagenamingpackage.impl.Main