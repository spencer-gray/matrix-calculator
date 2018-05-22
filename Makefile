all: matrix-calculator

typing-tutor: matrix-calculator.cpp
	g++ matrix-calculator.cpp -o matrix-calculator

clean:
	rm matrix-calculator

run:
	./matrix-calculator