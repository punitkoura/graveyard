Abstract - 
I'd like to improve on the test coverage of tor, which is not too good right now. Many of the code files are not tested at all, which would not be good for development, and debugging. 
    To do this, I'll write more unit tests for Tor, which may require refactoring of code to make the code more testable. To improve integration tests, I will be adding functionality to Chutney, the Tor testing framework. Testers will have the ability to script individual tor nodes via Stem, and Chutney will be used to verify, as well as test, certain parameters of the Tor network.
    
    

### What project would you like to work on?
    I would like to work on the project "Improving Test Coverage for Tor". Basically this project would be a combination of two parts - One would be adding more unit tests for the existing tor code base. This would require refactoring of certain parts of code to make the code more testable. Some of the existing test cases will also be improved if their code soverage is poor.
    The second major part of the project will be to improve integration test coverage of tor. As of now, Tor has a single shell script "test-network.sh" which does some basic test of Starting up somr network nodes and waiting for them to bootstrap. Thus, the project will also aim to improve the integration tests by adding additional functionality to Chutney, so that more complex tests can be applied to the network.
    
    
