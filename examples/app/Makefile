run: install
	FLASK_ENV=development FLASK_APP=app.py python3 -m flask run

run_chaos: install
	CHAOS=true CHAOS_DELAY_SECONDS=0.1 \
		FLASK_ENV=development FLASK_APP=app.py python3 -m flask run

install:
	pip3 install --user -r requirements.txt

bench:
	echo "query=Apples" > query.txt && \
	ab -c 1 -t 10 \
		-H "Cookie: sessionID=something" \
		-H "Content-type: application/x-www-form-urlencoded" \
		-p query.txt \
		http://127.0.0.1:5000/search

.PHONY: run run_chaos install bench