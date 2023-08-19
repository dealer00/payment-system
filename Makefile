CXXFLAGS += -I./include #-DDEBUG
DIR_BUILD := build
DIR_BUILD_APP := $(DIR_BUILD)/app
DIR_BUILD_TEST := $(DIR_BUILD)/test

OBJ_APP := $(DIR_BUILD_APP)/app.o

MODULE_CORE_SRC := $(shell find src/core/*.cpp -type f)
MODULE_CORE_NAMES := $(shell basename -s .cpp -a ${MODULE_CORE_SRC})
OBJS_MODULE_CORE := $(MODULE_CORE_NAMES:%=$(DIR_BUILD_APP)/core/%.o)

MODULE_TRANSACTION_SRC := $(shell find src/transaction/*.cpp -type f)
MODULE_TRANSACTION_NAMES := $(shell basename -s .cpp -a ${MODULE_TRANSACTION_SRC})
OBJS_MODULE_TRANSACTION := $(MODULE_TRANSACTION_NAMES:%=$(DIR_BUILD_APP)/transaction/%.o)

OBJS_MODULES := $(OBJS_MODULE_CORE) $(OBJS_MODULE_TRANSACTION)
OBJS := $(OBJ_APP) $(OBJS_MODULES)

all: bin/app bin/test

bin/app: $(OBJS)
	@mkdir -p $(dir $@)
	$(CXX) -o $@ $^

$(OBJ_APP): src/app.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $^ -o $@

$(DIR_BUILD_APP)/core/%.o: src/core/%.cpp
	@echo "Creating core target:" $@
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(DIR_BUILD_APP)/transaction/%.o: src/transaction/%.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

TEST_CORE_PAYROLL_DATABASE := $(DIR_BUILD_TEST)/core/PayrollDatabaseTest.o
TEST_TRANSACTION_ADD_SALARIED_EMPLOYEE_TRANSACTION := $(DIR_BUILD_TEST)/transaction/AddSalariedEmployeeTransactionTest.o

TESTS_TARGETS := $(TEST_CORE_PAYROLL_DATABASE) $(TEST_TRANSACTION_ADD_SALARIED_EMPLOYEE_TRANSACTION)

bin/test: $(TESTS_TARGETS) $(OBJS_MODULES)
	@mkdir -p $(dir $@)
	$(CXX) -o $@ src/test.cpp $^ $(CXXFLAGS) `pkg-config --cflags --libs gtest`

$(TEST_CORE_PAYROLL_DATABASE): test/core/PayrollDatabaseTest.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(TEST_TRANSACTION_ADD_SALARIED_EMPLOYEE_TRANSACTION): test/transaction/AddSalariedEmployeeTransactionTest.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clear
clear:
	rm -rf build bin
