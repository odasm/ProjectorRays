/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 */

#include <iostream>
#include <fstream>

#include "common/fileio.h"
#include "common/stream.h"

namespace Common {

bool readFile(const std::string &fileName, std::vector<uint8_t> &buf) {
	std::ifstream f;
	f.open(fileName, std::ios::in | std::ios::binary);

	if (f.fail())
		return false;

	f.seekg(0, std::ios::end);
	auto fileSize = f.tellg();
	f.seekg(0, std::ios::beg);
	buf.resize(fileSize);
	f.read((char *)buf.data(), fileSize);
	f.close();

	return true;
}

void writeFile(const std::string &fileName, const std::string &contents) {
	std::ofstream f;
	f.open(fileName, std::ios::out | std::ios::binary);
	f << contents;
	f.close();
}

void writeFile(const std::string &fileName, const uint8_t *contents, size_t size) {
	std::ofstream f;
	f.open(fileName, std::ios::out | std::ios::binary);
	f.write((char *)contents, size);
	f.close();
}

void writeFile(const std::string &fileName, const BufferView &view) {
	writeFile(fileName, view.data(), view.size());
}

} // namespace Common
