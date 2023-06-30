// import React, { useState, useEffect } from "react";
import { Progress, Space } from "antd";
import "../Global";
const App: React.FC = (props: any) => {
  
  const size: number = 180;
  return (
    <>
      <Space wrap>
        <div className="MARGIN-RIGHT MARGIN-LEFT">
          <Progress
            type="dashboard"
            percent={props.dataAll[0][0]/10}
            format={() => `${props.dataAll[0][0]} lx`}
            size={size}
            strokeColor={{ "0%": "#108ee9", "100%": "#87d068" }}
          />
          <div>
            <center>
              <p className="P2">光照强度</p>{" "}
            </center>
          </div>
        </div>
        <div className="MARGIN-RIGHT MARGIN-LEFT">
          <Progress
            type="dashboard"
            percent={props.dataAll[0][1]}
            format={(count) => `${count} °C`}
            size={size}
            strokeColor={{ "0%": "#108ee9", "100%": "#87d068" }}
          />
          <div>
            <center>
              <p className="P2">温度</p>{" "}
            </center>
          </div>
        </div>
        <div className="MARGIN-RIGHT MARGIN-LEFT">
          <Progress
            type="dashboard"
            percent={props.dataAll[0][2]}
            format={(count) => `${count} %`}
            size={size}
            strokeColor={{ "0%": "#108ee9", "120%": "#87d068" }}
          />
          <div>
            <center>
              <p className="P2">相对湿度</p>{" "}
            </center>
          </div>
        </div>
      </Space>
    </>
  );
};

export default App;
