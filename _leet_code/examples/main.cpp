#include "easyLevel.h"
#include "mediumLevel.h"
#include "hardLevel.h"

using namespace leetcode;

template <class _Ty>
void deallocated(_Ty * temp) {
    if (temp) {
        delete temp;
        temp = nullptr;
    }
}

int main()
{
    leetcode::easyLevel* easylevelController = new easyLevel();
    leetcode::mediumLevel* mediumlevelController = new mediumLevel();
    leetcode::hardLevel* hardlevelController = new hardLevel();

    auto getVal = mediumlevelController->simplifyPath("/.///NWtm/KBp/TQdj/a/v/rsJ/n/j/../../lsw/./j/../Gh/////gNBxM/./");
    std::cout << "res: " << getVal << std::endl;

    deallocated(easylevelController);
    deallocated(mediumlevelController);
    deallocated(hardlevelController);
    
    return 0;
}