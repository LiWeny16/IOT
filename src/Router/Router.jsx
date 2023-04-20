// import { BrowserRouter, Routes, Route } from "react-router-dom";
import { HashRouter, Route, Routes } from "react-router-dom";

import React, { Component } from "react";
// import Button from "../Components/Button.jsx";
// import Process from "../Components/Process.tsx"
import Index from "./index.jsx";
import Admin from "./admin.jsx";
import Fun from "./fun.jsx";
import Game from "./Game.jsx"
// import Navi from "../Components/Navigator.jsx";
// import { Switch } from "antd";
class Router extends Component {
  render() {
    return (
      <HashRouter basename="/">
        <Routes>
          <Route path="/" element={<Index />} />
          <Route path="/admin" element={<Admin />} />
          <Route path="/fun" element={<Fun />} />
          <Route path="/game" element={<Game />} />
        </Routes>
      </HashRouter>
    );
  }
}
// const About = () => {
//   return <div>聪花的主页</div>;
// };

export default Router;
