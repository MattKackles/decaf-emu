#pragma once
#include "coreinit_enum.h"
#include "coreinit_ios.h"

#include <common/be_val.h>
#include <common/structsize.h>
#include <cstdint>

namespace coreinit
{

/**
 * \defgroup coreinit_mcp MCP
 * \ingroup coreinit
 * @{
 */

#pragma pack(push, 1)

struct MCPSysProdSettings
{
   UNKNOWN(3);
   be_val<SCIRegion> platformRegion;
   UNKNOWN(0x7);
   be_val<SCIRegion> gameRegion;
   UNKNOWN(0x3A);
};
CHECK_OFFSET(MCPSysProdSettings, 0x03, platformRegion);
CHECK_OFFSET(MCPSysProdSettings, 0x0B, gameRegion);
CHECK_SIZE(MCPSysProdSettings, 0x46);

#pragma pack(pop)

IOSHandle
MCP_Open();

void
MCP_Close(IOSHandle handle);

MCPError
MCP_GetSysProdSettings(IOSHandle handle,
                       MCPSysProdSettings *settings);

/** @} */

} // namespace coreinit
