/**
Copyright (C) 2024  Matthew Kosarek

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
**/

#ifndef MIRACLEWM_WORKSPACE_CONTENT_H
#define MIRACLEWM_WORKSPACE_CONTENT_H

#include <miral/window_manager_tools.h>
#include <miral/minimal_window_manager.h>

namespace miracle
{
class OutputContent;
class MiracleConfig;
class TilingWindowTree;
class WindowMetadata;
class TilingInterface;

class WorkspaceContent
{
public:
    WorkspaceContent(
        OutputContent* screen,
        miral::WindowManagerTools const& tools,
        int workspace,
        std::shared_ptr<MiracleConfig> const& config,
        TilingInterface& node_interface);

    [[nodiscard]] int get_workspace() const;
    [[nodiscard]] std::shared_ptr<TilingWindowTree> get_tree() const;
    void show(std::vector<std::shared_ptr<WindowMetadata>> const&);
    std::vector<std::shared_ptr<WindowMetadata>> hide();

    bool has_floating_window(miral::Window const&);
    void add_floating_window(miral::Window const&);
    void remove_floating_window(miral::Window const&);
    std::vector<miral::Window> const& get_floating_windows() { return floating_windows; }

private:
    miral::WindowManagerTools tools;
    std::shared_ptr<TilingWindowTree> tree;
    int workspace;
    std::vector<miral::Window> floating_windows;
};

} // miracle

#endif //MIRACLEWM_WORKSPACE_CONTENT_H
