#include "Question.h"
#include "Fraction.h"

Question::Question() {
  amount = 0;
  number_type = ALL_INTEGER;
  if_pow_operator = false;
}

int Question::GenerateAndSave(int amount) {
  Question::QuestionGenerator generator;
  //调用QuestionGenerator类的Generate()
  for (int i = 0; i < amount; i++) {
    generator.Generate(*this);
  }
  
  return 1;
}

Fraction Question::Calculate(int index) {
  Question::QuestionCalculator calculator;
  return calculator.Calculate(index, *this);
  
}