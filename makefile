CXX ?= g++

DEBUG ?= 1
ifeq ($(DEBUG), 1)
    CXXFLAGS += -g
else
    CXXFLAGS += -O2

endif

fetcher: main.cpp  ./CoinMarketCap.cpp  ./HttpClient.cpp  
	$(CXX) -o fetcher  $^ $(CXXFLAGS) -ljsoncpp -lcurl

clean:
	rm  -r fetcher