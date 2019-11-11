SRCS = ./src/CRtspSession.cpp ./src/CStreamer.cpp ./src/SimStreamer.cpp

run: *.cpp ./src/*
	skill testserver
	g++ -o testserver -I ./src -I . *.cpp $(SRCS)
	./testserver