import "tachyons";
import React from "react";
import { render } from "react-dom";

import Form from "./components/Form";
import form from "./form";

import DevTools from "mobx-react-form-devtools";

DevTools.register({ form });
DevTools.select("form");
// DevTools.open(true);

render(
  <div>
    <DevTools.UI />
    <Form form={form} />
  </div>,
  document.getElementById("root")
);
