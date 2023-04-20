import React from "react";
import ReactDOM from "react-dom/client";
import App from "./App.jsx";
import { reactDOMType } from "./a.d.js";
import "./css/index.css";
let rootElement: reactDOMType | any = document.getElementById("root");
const root = ReactDOM.createRoot(rootElement);
root.render(
    <App />
);
