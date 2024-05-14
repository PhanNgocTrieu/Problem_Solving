#include "easyLevel.h"
#include "mediumLevel.h"
#include "hardLevel.h"

using namespace leetcode;
using namespace std;
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
#if 0
    auto getVal = mediumlevelController->simplifyPath("/.///NWtm/KBp/TQdj/a/v/rsJ/n/j/../../lsw/./j/../Gh/////gNBxM/./");
    std::cout << "res: " << getVal << std::endl;
#endif
    vector<vector<int>> data = {
        {0, 6, 0},
        {5, 8, 7},
        {0, 9, 0}
    };
    std::cout << mediumlevelController->getMaximumGold(data) << std::endl;
    deallocated(easylevelController);
    deallocated(mediumlevelController);
    deallocated(hardlevelController);
    
    return 0;
}