#ifndef APPJS_BASE_NATIVE_MENU_H
#define APPJS_BASE_NATIVE_MENU_H
#pragma once

#include "appjs.h"
#include "include/cef_browser.h"
#include "includes/util.h"
#include <node.h>
#include <vector>

namespace appjs {

class NativeMenu {

public:
  NativeMenu(Settings* settings);
  ~NativeMenu();
  void Init(Settings* settings);

  void Emit(v8::Handle<v8::Value>* args,int);
  void Emit(const char* event);
  void Emit(const char* event, v8::Handle<v8::Value> arg);

  void SetV8Handle(v8::Handle<v8::Object> v8handle) {v8handle_ = v8handle;};
  v8::Handle<v8::Object> GetV8Handle() {return v8handle_;};
#ifdef __LINUX__
  int AddSubMenu(GtkWidget*,Settings*);
  bool Attach(GtkMenuShell*);
#endif

private:
  v8::Handle<v8::Object> v8handle_;
  bool attached_;

#ifdef __LINUX__
  //GtkWidget* menu_;
  std::vector<GtkWidget*> menuItems_;
  GtkMenuShell* menu_;
#endif

};

} /* appjs */

#endif /* end of APPJS_BASE_NATIVE_MENU_H */
