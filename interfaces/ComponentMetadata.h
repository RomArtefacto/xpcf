/**
 * @copyright Copyright (c) 2017 B-com http://www.b-com.com/
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * @author Loïc Touraine
 *
 * @file
 * @brief description of file
 * @date 2017-04-28
 */

#ifndef __ComponentMetadata_H__
#define __ComponentMetadata_H__

#include "XPCF_definitions.h"
#include <boost/uuid/uuid.hpp>

#include <string>
#include <vector>
#include "InterfaceMetadata.h"

namespace org {
namespace bcom {
namespace xpcf {

class XPCF_EXPORT_API ComponentMetadata : public InterfaceMetadata {
public:
  ComponentMetadata() = delete;
  ComponentMetadata(const char* name, const uuids::uuid& componentID, const uuids::uuid& containerUUID);
  ComponentMetadata(const char* name, const char *componentID, const char *containerUUID);
  virtual ~ComponentMetadata();

  void addInterface(const uuids::uuid& interfaceUUID);
  uuids::uuid getInterface(int i) const;
  int getNbInterfaces() const;

  uuids::uuid getContainerUUID() const;


private:
  void setContainerUUID(const char * containerUUID);
  std::vector<uuids::uuid> m_interfaceUUIDs;
  uuids::uuid m_containerUUID;
};

}}} //namespace org::bcom::xpcf

#endif
