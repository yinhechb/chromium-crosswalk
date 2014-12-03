// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "ash/host/ash_window_tree_host.h"

#include "ash/host/ash_window_tree_host_init_params.h"
#include "ash/host/root_window_transformer.h"
#include "ash/host/transformer_helper.h"
#include "base/command_line.h"
#include "ui/aura/window_tree_host_ozone.h"
#include "ui/gfx/geometry/insets.h"
#include "ui/gfx/transform.h"

namespace ash {
namespace {

class AshWindowTreeHostOzone : public AshWindowTreeHost,
                               public aura::WindowTreeHostOzone {
 public:
  explicit AshWindowTreeHostOzone(const gfx::Rect& initial_bounds);
  virtual ~AshWindowTreeHostOzone();

 private:
  // AshWindowTreeHost:
  virtual void ToggleFullScreen() override;
  virtual bool ConfineCursorToRootWindow() override;
  virtual void UnConfineCursor() override;
  virtual void SetRootWindowTransformer(
      scoped_ptr<RootWindowTransformer> transformer) override;
  virtual gfx::Insets GetHostInsets() const override;
  virtual aura::WindowTreeHost* AsWindowTreeHost() override;
  virtual void SetRootTransform(const gfx::Transform& transform) override;
  virtual gfx::Transform GetRootTransform() const override;
  virtual gfx::Transform GetInverseRootTransform() const override;
  virtual void UpdateRootWindowSize(const gfx::Size& host_size) override;
  virtual void DispatchEvent(ui::Event* event) override;

  TransformerHelper transformer_helper_;

  DISALLOW_COPY_AND_ASSIGN(AshWindowTreeHostOzone);
};

AshWindowTreeHostOzone::AshWindowTreeHostOzone(const gfx::Rect& initial_bounds)
    : aura::WindowTreeHostOzone(initial_bounds),
      transformer_helper_(this) {}

AshWindowTreeHostOzone::~AshWindowTreeHostOzone() {}

void AshWindowTreeHostOzone::ToggleFullScreen() {
  NOTIMPLEMENTED();
}

bool AshWindowTreeHostOzone::ConfineCursorToRootWindow() {
  return false;
}

void AshWindowTreeHostOzone::UnConfineCursor() {
  NOTIMPLEMENTED();
}

void AshWindowTreeHostOzone::SetRootWindowTransformer(
    scoped_ptr<RootWindowTransformer> transformer) {
  transformer_helper_.SetRootWindowTransformer(transformer.Pass());
}

gfx::Insets AshWindowTreeHostOzone::GetHostInsets() const {
  return transformer_helper_.GetHostInsets();
}

aura::WindowTreeHost* AshWindowTreeHostOzone::AsWindowTreeHost() {
  return this;
}

void AshWindowTreeHostOzone::SetRootTransform(const gfx::Transform& transform) {
  transformer_helper_.SetTransform(transform);
}

gfx::Transform AshWindowTreeHostOzone::GetRootTransform() const {
  return transformer_helper_.GetTransform();
}

gfx::Transform AshWindowTreeHostOzone::GetInverseRootTransform() const {
  return transformer_helper_.GetInverseTransform();
}

void AshWindowTreeHostOzone::UpdateRootWindowSize(const gfx::Size& host_size) {
  transformer_helper_.UpdateWindowSize(host_size);
}

void AshWindowTreeHostOzone::DispatchEvent(ui::Event* event) {
  if (event->IsLocatedEvent())
    TranslateLocatedEvent(static_cast<ui::LocatedEvent*>(event));
  SendEventToProcessor(event);
}

}  // namespace

AshWindowTreeHost* AshWindowTreeHost::Create(
    const AshWindowTreeHostInitParams& init_params) {
  return new AshWindowTreeHostOzone(init_params.initial_bounds);
}

}  // namespace ash
