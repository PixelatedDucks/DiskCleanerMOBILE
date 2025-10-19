#include <iostream>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

int main() {
    std::string folder;
    std::cout << "Enter folder path: ";
    std::getline(std::cin, folder);

    if (!fs::exists(folder)) {
        std::cout << "Folder does not exist!\n";
        return 1;
    }

    std::vector<fs::path> files;
    std::cout << "Files found:\n";

    for (auto& p : fs::directory_iterator(folder)) {
        if (fs::is_regular_file(p)) {
            std::cout << p.path().string() << std::endl;
            files.push_back(p.path());
        }
    }

    char choice;
    std::cout << "Delete all files? (y/n): ";
    std::cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        int deleted = 0;
        for (auto& f : files) {
            try {
                fs::remove(f);
                deleted++;
            } catch (...) {
                // ignore errors
            }
        }
        std::cout << "Deleted " << deleted << " files.\n";
    } else {
        std::cout << "No files deleted.\n";
    }

    return 0;
}
