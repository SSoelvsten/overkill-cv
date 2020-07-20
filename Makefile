python=python3

compile:
	@mkdir -p build
	@${python} compile.py

clean:
	@rm -rf build/
