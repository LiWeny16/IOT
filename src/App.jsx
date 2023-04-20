/* eslint-disable no-unused-vars */
import React, { useState, useRef, useEffect } from "react";
import "antd/dist/reset.css";
// import { Button } from "antd";
import Navi from "./Components/Navigator";
// import { Routes, Route, BrowserRouter } from "react-router-dom";
import RouterIndex from "./Router/Router.jsx";
import { Col, Row } from "antd";
import NaviTop from "./Components/NaviTop.tsx";
import FloatBtn from "./Components/FloatButton"
// import AlertAll,{AlertTag} from "./Components/alert.tsx"
// const LOAL_STORAGE_KEY = 'todoApp'

function App() {
  return (
    <>
    <FloatBtn />
      <Row>
        <Col span={24}>
          <div>
            <NaviTop />
          </div>
        </Col>
      </Row>
      <Row>
        <Col className="gutter-row" span={6}>
          <div>
            <Navi />
          </div>
        </Col>
        <Col className="gutter-row" span={18}>
          <div style={style}>
            <RouterIndex />
          </div>
        </Col>
      </Row>
    </>
  );
}

const style = { background: "white", padding: "10vh 0vh" };
export default App;
