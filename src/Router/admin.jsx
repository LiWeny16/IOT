import React, { Component } from "react";
import Switcher from "../Components/Switcher.tsx";
import QRCode from "../Components/QRcode.tsx";
export default class admin extends Component {
  render() {
    return (
      <>
        <div className="FLEX ROW">
          <div className="FLEX COL MARGIN">
            <div className="MARGIN">
              <p className="P2">湿度传感器</p>
              <Switcher />
            </div>
            <div className="MARGIN">
              <p className="P2">光照传感器</p>
              <Switcher />
            </div>
          </div>
          <div className="FLEX COL MARGIN">
            <div className="MARGIN">
              <p className="P2">灯光控制器</p>
              <Switcher />
            </div>
            <div className="MARGIN">
              <p className="P2">灯光控制器2</p>
              <Switcher />
            </div>
          </div>
          <div className="FLEX MARGIN">
            <QRCode />
          </div>
        </div>
      </>
    );
  }
}
