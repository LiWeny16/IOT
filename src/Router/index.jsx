import React, { useEffect, useState,useRef } from "react";
import Process from "../Components/Process.tsx";
import Statisic from "../Components/Statistic.tsx";
import Calendar from "../Components/Calendar.tsx";
import axios from "axios";
// import NaviTop from "../Components/NaviTop.tsx";
function App() {
  const [dataAll, setdataAll] = useState("/?"); // 定义state:count
  const dataAllRef = useRef(dataAll);
  useEffect(() =>{
    dataAllRef.current = dataAll;
  });
  useEffect(() => {
    const t = setInterval(() => {
      getData().then((e) => {
        let data = e.data;
        data = data.replace(/(\r)|(\?)/g, "");
        data = data.split(",");
        console.log(data);
        setdataAll(() => data);
        console.log(dataAll);
      });
    }, 4000);

    return () => {
      clearTimeout(t);
    };
  }, []);

  return (
    <>
      <div className="FLEX COL">
        <div className="FLEX ROW">
          <div className="MARGIN">
            <Calendar />
          </div>
          <div className="MARGIN">
            <div>
              <Process dataAll={dataAll}></Process>
            </div>
            <div>
              <Statisic dataAll={dataAll}></Statisic>
            </div>
          </div>
        </div>
      </div>
    </>
  );
}
export default App;

function getData() {
  return new Promise((resolve) => {
    let axiosConfig;
    axiosConfig = {
      method: "get",
      url: "http://10.0.0.133/getdata",
    };
    axios(axiosConfig)
      .then((res) => {
        resolve(res);
      })
      .catch((error) => {
        console.log(error);
      });
  });
}
