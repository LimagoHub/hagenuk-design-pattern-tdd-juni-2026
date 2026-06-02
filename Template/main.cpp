#include <iostream>
#include <memory>

#include "processor/AbstractFileProcessor.h"
#include "processor/CharacterCounter.h"
#include "processor/LineCounter.h"

int main() {
    std::shared_ptr<processor::AbstractFileProcessor> processor = std::make_shared<processor::LineCounter>();
    processor->run("../data/blind.txt");
    return 0;
}
