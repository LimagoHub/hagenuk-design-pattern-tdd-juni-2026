#include <iostream>
#include <memory>

#include "processor/FileProcessor.h"
#include "processor/CharacterCounter.h"
#include "processor/LineCounter.h"

int main() {


    processor::CharacterCounter character_counter;
    processor::LineCounter line_counter;

    std::shared_ptr<processor::FileProcessor> processor = std::make_shared<processor::FileProcessor>();

    processor->addHandler(character_counter);
    processor->addHandler(line_counter);

    processor->run("../data/blind.txt");
    return 0;
}
