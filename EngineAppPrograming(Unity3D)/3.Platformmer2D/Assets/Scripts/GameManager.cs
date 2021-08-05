﻿using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameManager : MonoBehaviour
{
    public CameraTracker cameraTracker;

    public Responner responnerPlayer;
    public Responner responnerOpossum;
    public Responner responnerEagle;

    public float DeathZoneY = -1;

    public void DeathZoneGizmo()
    {
        Vector3 vStartPos = new Vector3(-9999999999, DeathZoneY, 0);
        Vector3 vEndPos = new Vector3(9999999999, DeathZoneY, 0);
        Gizmos.color = Color.red;
        Gizmos.DrawLine(vStartPos, vEndPos);
    }

    //싱글톤: 게임관리자를 어떤객체든 쉽게 접근하게 만들수있다.
    static GameManager instance;
    public static GameManager GetInstance()
    {
        return instance;
    }

    // Start is called before the first frame update
    void Start()
    {
        instance = this;
        SetGUIScene(curGUIState);
    }

    // Update is called once per frame
    void Update()
    {
        if(cameraTracker.objTarget == null)
            cameraTracker.objTarget = responnerPlayer.objPlayer;

        UpdateEagleRetrunPointCheck();
    }

    private void UpdateEagleRetrunPointCheck()
    {
        if(responnerEagle.objPlayer)
        {
            Eagle eagle = responnerEagle.objPlayer.GetComponent<Eagle>();
            if(eagle.objResponPoint ==null)
                eagle.objResponPoint = responnerEagle.gameObject;
        }
    }

    private void OnDrawGizmos()
    {
        DeathZoneGizmo();
    }

    public void EventChageScene(int stateNumber)
    {
        SetGUIScene((E_GUI_STATE)stateNumber);
    }

    public List<GameObject> listGUIScenes;
    public enum E_GUI_STATE { TITLE, THEEND, GAMEOVER, PLAY }
    public E_GUI_STATE curGUIState;
    public void ShowScenec(E_GUI_STATE state)
    {
        for (int i = 0; i < listGUIScenes.Count; i++)
        {
            if ((E_GUI_STATE)i == state)
                listGUIScenes[i].SetActive(true);
            else
                listGUIScenes[i].SetActive(false);
        }
    }
    public void SetGUIScene(E_GUI_STATE state)
    {
        switch (state)
        {
            case E_GUI_STATE.TITLE:
                break;
            case E_GUI_STATE.THEEND:
                break;
            case E_GUI_STATE.GAMEOVER:
                break;
            case E_GUI_STATE.PLAY:
                break;
        }
        ShowScenec(state);
        curGUIState = state;
    }
    public void UpdateState()
    {
        switch (curGUIState)
        {
            case E_GUI_STATE.TITLE:
                break;
            case E_GUI_STATE.THEEND:
                break;
            case E_GUI_STATE.GAMEOVER:
                break;
            case E_GUI_STATE.PLAY:
                break;
        }
    }

}